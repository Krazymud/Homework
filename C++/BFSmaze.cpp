#include <iostream>
#include <queue>
#include <string>
using namespace std;
struct node{
	int x;
	int y;
};
int main() {
	int n, m, end[2] = { 0 };
	node start;
	cin >> n >> m;
	string* maze = new string[n];
	for (int i = 0; i < n; i++) {
		cin >> maze[i];
		for (int j = 0; j < m; j++) {
			if (maze[i][j] == 'S') {
				start.x = i;
				start.y = j;
			}
			if (maze[i][j] == 'E') {
				end[0] = i;
				end[1] = j;
			}
		}
	}
	queue<node>q1;
	q1.push(start);
	while (1) {
		if (q1.empty()) {
			cout << -1 << endl;
			break;
		}
		int s_0 = q1.front().x, s_1 = q1.front().y;
		if (maze[s_0][s_1] == 'E'){
			int x = (start.x > end[0]) ? (start.x - end[0]) : (end[0] - start.x);
			int y = (start.y > end[1]) ? (start.y - end[1]) : (end[1] - start.y);
			cout << x + y << endl;
			break;
		}
		if (maze[s_0 + 1][s_1] != '#' && maze[s_0 + 1][s_1] != '!') {
			node temp;
			temp.x = s_0 + 1; temp.y = s_1;
			q1.push(temp);
			if (maze[s_0 + 1][s_1] != 'E')
				maze[s_0 + 1][s_1] = '!';
		}
		if (maze[s_0 - 1][s_1] != '#' && maze[s_0 - 1][s_1] != '!') {
			node temp;
			temp.x = s_0 - 1; temp.y = s_1;
			q1.push(temp);
			if (maze[s_0 - 1][s_1] != 'E')
				maze[s_0 - 1][s_1] = '!';
		}
		if (maze[s_0][s_1 + 1] != '#' && maze[s_0][s_1 + 1] != '!') {
			node temp;
			temp.x = s_0; temp.y = s_1 + 1;
			q1.push(temp);
			if (maze[s_0][s_1 + 1] != 'E')
				maze[s_0][s_1 + 1] = '!';
		}
		if (maze[s_0][s_1 - 1] != '#' && maze[s_0][s_1 - 1] != '!') {
			node temp;
			temp.x = s_0; temp.y = s_1 - 1;
			q1.push(temp);
			if (maze[s_0][s_1 - 1] != 'E')
				maze[s_0][s_1 - 1] = '!';
		}
		if (maze[s_0][s_1] == 'S')
			maze[s_0][s_1] = '!';
		q1.pop();
	}
	delete[] maze;
	return 0;
}