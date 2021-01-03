/*
Here, I am showing four solutions:

    Naïve sorting solution, O(n log n)
    Short and efficient O(n) solution using nth_element <-- recommended
    Simple implementation of quickselect, with O(n) average case complexity
    Improved quickselect with O(n) worst case complexity

Solution 1: Sorting

We can just sort our points by the distance using a multimap (value is the index in the input array). Then we can take K first elements from the multimap and build the result vector.

vector<vector<int>> kClosest(vector<vector<int>>& ps, int K) {
  multimap<int, int> m;
  for (int i = 0; i < ps.size(); ++i)
    m.insert({ ps[i][0] * ps[i][0] + ps[i][1] * ps[i][1], i });
  vector<vector<int>> res;
  for (auto it = m.begin(); K > 0; ++it, --K) res.push_back(ps[it->second]);
  return res;
}

Solution 2: nth_element

However, multimap sorts all elements, and what we need is just re-arrange elements so that none of the elements preceding Kth are greater than it, and none of the elements following it are less. To accomplish this, we could use partial_sort or nth_element functions, and the latter is better suited for this problem as we do not care about the order of the returning elements.

The nth_element function is typically implemented using Introselect, which brings the average complexity down to O(n).

vector<vector<int>> kClosest(vector<vector<int>>& ps, int K) {
  nth_element(begin(ps), begin(ps) + K, end(ps), [](vector<int> &a, vector<int> &b) {
      return a[0]*a[0]+a[1]*a[1] < b[0]*b[0]+b[1]*b[1];
  });
  ps.resize(K);
  return ps;
}

Solution 3: Quickselect

If you don't want to use the library function, below is a sample implementation using quickselect.
 I implemented it in a generic way to keep the same signature as for nth_element.
 You can have a simpler implementation without using generics, like Approach 2: Divide and Conquer.

For this implementation, we use the last element as a pivot. This gives us average O(n) complexity.

vector<vector<int>> kClosest(vector<vector<int>>& ps, int K) {
  quickselect(begin(ps), end(ps), K, [](vector<int> &a, vector<int> &b) {
      return a[0]*a[0]+a[1]*a[1] < b[0]*b[0]+b[1]*b[1];
  });
  ps.resize(K);
  return ps;
}
template<class RndIt, class Compare> void quickselect(RndIt first, RndIt end, int K, Compare cmp) {
  auto p = partition(first, end, cmp);
  if (p - first + 1 == K) return;
  if (p - first + 1 < K) quickselect(p + 1, end, K - (p - first + 1), cmp);
  else quickselect(first, p, K, cmp);
}
template<class RndIt, class Compare> RndIt partition(RndIt first, RndIt end, Compare cmp) {
  auto last = next(end, -1);
  auto pivot = *last;
  while (first < last) {
    while (cmp(*first, pivot)) ++first;
    while (cmp(pivot, *last)) --last;
    if (first < last) swap(*first, *last);
  }
  return first;
}

Solution 4: Improved quickselect

In the previous solution, we used the last element as a pivot. It's a simple approach, but in the worst case the
 runtime can be O(n * n). To combat that, we coluld use the median-of-median method to pick our pivot.

 */

#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<vector<int>> kClosest(vector<vector<int>>& ps, int K) {
    multimap<int, int> m;
    for (int i = 0; i < ps.size(); ++i)
        m.insert({ ps[i][0] * ps[i][0] + ps[i][1] * ps[i][1], i });
    vector<vector<int>> res;
    for (auto it = m.begin(); K > 0; ++it, --K) res.push_back(ps[it->second]);
    return res;
}



int main() {
    vector<vector<int>> points {{1,3}, {-2,2}};
    int K = 1;
    std::cout << "Input: points = [[1,3],[-2,2]], K = 1" << std::endl;
    std::cout << "Expected Output: [[-2,2]]" << std::endl;
    points = kClosest(points, K);
    std::cout << "Actual Output: [";
    for(auto a: points) {
        std::cout << "[" << a[0] << "," << a[1] << "] ";
    }
    std::cout << "]"<< std::endl;

    points = {{3,3}, {5,-1}, {-2,4}};
    K = 2;
    std::cout << "Input: points =  [[3,3],[5,-1],[-2,4]], K = 2" << std::endl;
    std::cout << "Expected Output: [[3,3],[-2,4]] or [[-2,4],[3,3]]" << std::endl;
    points = kClosest(points, K);
    std::cout << "Actual Output: [";
    for(auto a: points) {
        std::cout << "[" << a[0] << "," << a[1] << "] ";
    }
    std::cout << "]"<< std::endl;

    return 0;
}
