# [Gold IV] hugo - 3207 

[문제 링크](https://www.acmicpc.net/problem/3207) 

### 성능 요약

메모리: 21660 KB, 시간: 1244 ms

### 분류

다이나믹 프로그래밍

### 제출 일자

2024년 4월 6일 18:17:14

### 문제 설명

<p>Hugo is a PC game hero that has to collect as many apples falling down the trees as possible. He walks, or runs, at the bottom of a screen where a path divided into N equal squares is drawn. The squares are labelled by the numbers from 1 (the leftmost square) to N (the rightmost square). There is an apple tree rising above each square. Every now and then an apple falls down from a tree on a screen.</p>

<p>At the beginning of a game Hugo is positioned at the middle square (there are odd number of squares). If Hugo is positioned at the square P, then the next second he can move to the left to the square P-1, or to the right to the square P+1, or he may choose to stay at the square P. He stays at a square one second or more. If Hugo is positioned at the right square he will catch the falling apple. He knows in advance when an apple will fall and from which tree.</p>

<p>Write a program that will compute the maximal number of apples Hugo can catch.</p>

### 입력 

 <p>The first line of input contains an odd integer N, 1 ≤ N ≤ 999, the number of squares. The next N lines contain data about falling apples.</p>

<p>Data concerning M-th tree are contained in the (M+1)st line. Each of those lines contains an integer number K, 1 ≤ K ≤ 3000, followed by K ascending integers. Those numbers denotes times when apples will fall from the tree. The largest time would be less than or equal to 100,000.</p>

### 출력 

 <p>The first and only line of output should contain the maximal number of apples that can be caught.</p>

