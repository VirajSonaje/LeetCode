import heapq

class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:

        graph = [[] for _ in range(n+1)]

        for time in times:
            a, b, w = time
            graph[a].append((b, w))

        distance = [float('inf')] * (n + 1)
        distance[k] = 0

        pq = []
        closed_nodes = set()

        heapq.heappush(pq, (0, k))

        while len(pq) != 0:

            current_node_distance, current_node = heapq.heappop(pq)

            if current_node in closed_nodes:
                continue

            for neighbor, w in graph[current_node]:

                if distance[neighbor] > current_node_distance + w:
                    distance[neighbor] = current_node_distance + w
                    heapq.heappush(pq, (distance[neighbor], neighbor))

            closed_nodes.add(current_node)

        print(distance)

        ans = -float('inf')
        for i in range(1, len(distance)):
            if distance[i] == float('inf'):
                return -1
            elif distance[i] == 0:
                continue

            ans = max(ans, distance[i])
        
        return ans








        

