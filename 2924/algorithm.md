# Input
정수 N, A, B, C, D (1 ≤ N ≤ 500 000, A ≤ B ≤ 10^12, 0 ≤ C, D ≤ N, C + D < N)

# Output
[A, B]번째 수열이 [C+1, N-D] 번쨰 원소들이 1번째 수열과 같은 횟수


# Algo
순열 사이클을 UnionFind 로 구한다.
[C+1, N-D] 번째 원소들이 포함된 사이클의 lcm을 구한다
[1, B] 에서의 cnt - [1, A-1] 에서의 cnt 로 [A, B] cnt를 구한다.

