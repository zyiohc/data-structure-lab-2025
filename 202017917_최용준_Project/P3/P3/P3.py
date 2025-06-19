# -*- coding: utf-8 -*-
from collections import deque

input = [[4, 3, 2, 1],
         [0, 0, 0, 0],
         [0, 0, 9, 0],
         [1, 2, 3, 4]]
N = 4

def problem3(input):
    bear_size = 2
    honeycomb_count = 0
    time = 0
    bear_x, bear_y = 0, 0

    # forest 리스트 초기화
    forest = [row[:] for row in input]

    # 곰의 초기 위치 찾기
    for i in range(N):
        for j in range(N):
            if forest[i][j] == 9:
                bear_x, bear_y = i, j
                forest[i][j] = 0

    # 방향: 상, 좌, 우, 하
    dx = [-1, 0, 0, 1]
    dy = [0, -1, 1, 0]

    def bfs(x, y, size):
        visited = [[-1]*N for _ in range(N)]
        queue = deque()
        queue.append((x, y))
        visited[x][y] = 0
        candidates = []

        while queue:
            cx, cy = queue.popleft()
            for dir in range(4):
                nx = cx + dx[dir]
                ny = cy + dy[dir]
                if 0 <= nx < N and 0 <= ny < N:
                    if visited[nx][ny] == -1 and forest[nx][ny] <= size:
                        visited[nx][ny] = visited[cx][cy] + 1
                        queue.append((nx, ny))
                        if 0 < forest[nx][ny] < size:
                            candidates.append((visited[nx][ny], nx, ny))

        if not candidates:
            return None
        candidates.sort()
        return candidates[0]  # 거리, x, y 순으로 정렬됨

    while True:
        result = bfs(bear_x, bear_y, bear_size)
        if result is None:
            break
        dist, nx, ny = result
        bear_x, bear_y = nx, ny
        time += dist
        honeycomb_count += 1
        forest[nx][ny] = 0
        if honeycomb_count == bear_size:
            bear_size += 1
            honeycomb_count = 0

    return time

result = problem3(input)

assert result == 14
print("correct")
