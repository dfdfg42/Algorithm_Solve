# [Gold IV] Bingo Ties - 16624 

[문제 링크](https://www.acmicpc.net/problem/16624) 

### 성능 요약

메모리: 2024 KB, 시간: 108 ms

### 분류

브루트포스 알고리즘

### 제출 일자

2024년 9월 11일 14:27:19

### 문제 설명

<p>Bingo is a game of chance played by a group of players. Each player has his or her own bingo card with a 5-by-5 grid of numbers. Each number appears at most once per card. The bingo caller calls out a sequence of randomly drawn numbers, and the players mark the numbers that appear on their card as they are called out. The winner is the player that completes a line of five marked numbers (horizontally, vertically or diagonally) on his or her card. The winning player then yells “bingo” and the game ends.</p>

<p>You have been volunteering with a local youth group and have been running bingo games for the children. They love bingo, but every time two or more kids yell “bingo” at the same time, a spirited “disagreement” breaks out. You’ve created a slightly modified version of bingo (in the hopes of introducing fewer ties): the cards are 5-by-5 grids with a number from 1 to 3 000 in each of the 25 cells, and a winner is only declared when a player has 5 numbers in a row. Note that in this new game, players cannot win via columns or diagonals.</p>

<p>Alas, these changes did not eliminate ties or the subsequent disagreements. To prevent further disagreements, you’ve decided to analyze the sets of cards to determine if there is any possibility that a tie (where two kids can yell bingo at the same time) can occur. Write a program that takes a collection of bingo cards and determines if there is any possible sequence of numbers that could be called so that the game ends, and a tie between two or more players occurs, when the last number in the sequence is called.</p>

<p>For example, consider the following two bingo cards:</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/0037718c-25e4-406c-a822-e15f46d47b29/-/preview/" style="width: 341px; height: 104px;"></p>

<p>Then this set of two cards could result in a tie if the sequence of numbers called was</p>

<p style="text-align: center;">40 61 64 10 57 49 11 31 25</p>

<p>This sequence would result in the card on the left completing the third row and the card on the right completing the fourth row when the number 25 is called.</p>

### 입력 

 <p>The first line of the input is an integer n (2 ≤ n ≤ 100), the number of bingo cards. After the first line are the n bingo cards, each separated from the next by a blank line of input.</p>

<p>Each bingo card consists of five lines of input. Each line consists of five integers in the range from 1 to 3 000. The numbers on each bingo card are unique.</p>

### 출력 

 <p>If no ties are possible between any two cards, output “no ties” on a single line. Otherwise, output the numbers of the lowest numbered pair of cards for which a tie could occur, where the cards are numbered from 1 to n in the order that they appear in the input. If multiple pairs of cards can tie, output the pair that is lexicographically smallest (with a smallest first card number, and then a smallest second card number).</p>

