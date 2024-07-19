#include <algorithm>
#include <iostream>
#include <set>
using namespace std;

int main() {

	int n, m;
	cin >> n >> m;

	int cities[n];
	set<int> towers;
	for (int i = 0; i < n; i++) { cin >> cities[i]; }
	for (int i = 0; i < m; i++) {
	    int tower;
		cin >> tower;
		towers.insert(tower);
	}

	int r = 0;
	for (int i = 0; i < n; i++) {
		int dist = INT32_MAX;

		// find closest tower to the right of the city
		auto closesttower = towers.lower_bound(cities[i]);
		if (closesttower != towers.end()) {
			// if a tower is found, update the distance
			dist = *closesttower - cities[i]; // get distance
		}

		// find closest tower to the left of the city
		if (closesttower != towers.begin()) {
			closesttower--; // (for left)
			// update dist with the minimum of the distances
			dist = min(dist, cities[i] - *closesttower);
		}
		r = max(r, dist); // check its max
	}

	cout << r << endl;
	return 0;
}