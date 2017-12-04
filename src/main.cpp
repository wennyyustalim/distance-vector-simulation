#include <stdio.h>

typedef struct {
	int distance = -1;
	int next_hop = -1;
} tuple;

int main() {
	//read inputs
	int n_node, n_edge, n_scenario;
	scanf("%d %d", &n_node, &n_edge);
	tuple table[n_node][n_node];
	for (int i = 0; i < n_edge; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		a--; b--;
		table[a][b].distance = 1;
		table[b][a].distance = 1;
		table[a][b].next_hop = b;
		table[b][a].next_hop = a;
	}
	//initialize routing tables
	for (int i = 0; i < n_node; i++) {
		for (int j = 0; j < n_node; j++) {
			if (i==j) {
				table[i][j].distance = 0;
				table[i][j].next_hop = i;
			}
		}
	}
	scanf("%d", &n_scenario);
	for (int i = 0; i < n_scenario; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		a--, b--;
		if(table[a][b].distance > 0) {
			for(int x = 0; x < n_node; x++) {
				if (table[a][x].distance > 0 && x != b) {
					int distance = table[b][a].distance + table[a][x].distance;
					if(table[b][x].distance == -1) {
						table[b][x].distance = distance;
						table[b][x].next_hop = a;
					} else if (table[b][x].distance > 0) {
						if (table[b][x].distance > distance) {
							table[b][x].distance = distance;
							table[b][x].next_hop = a;
						} else if (table[b][x].distance == distance) {
							table[b][x].next_hop = (a < table[b][x].next_hop) ? a : table[b][x].next_hop;
						}
					}
				}
			}
		}
	}

	//print output
	for (int i = 0; i < n_node; i++) {
		for (int j = 0; j < n_node; j++) {
			int next_hop = (table[i][j].next_hop == -1) ? -1 : table[i][j].next_hop+1;
			printf("%d %d\n", table[i][j].distance, next_hop);
		}
	}

	return 0;
}
