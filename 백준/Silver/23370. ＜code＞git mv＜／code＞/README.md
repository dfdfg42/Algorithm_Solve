# [Silver I] <code>git mv</code> - 23370 

[문제 링크](https://www.acmicpc.net/problem/23370) 

### 성능 요약

메모리: 8164 KB, 시간: 32 ms

### 분류

구현, 파싱, 문자열

### 제출 일자

2025년 2월 23일 12:30:47

### 문제 설명

<p>During development, you recently moved a file from one location to another. To keep your development team up to date with the change you made, you want to send them a short description of the change, without making use of any versioning software.</p>

<p>Both the source location and destination are valid Unix path names, that is, a nonempty string consisting of lowercase letters and "<code>/</code>" such that no "<code>/</code>" occurs at the begin or the end, nor does it contain two consecutive forward slashes.</p>

<p>You need to find the shortest string of the form "<code>A{B => C}D</code>" such that:</p>

<ul>
	<li>The source location is "<code>ABD</code>" and the destination is "<code>ACD</code>", where double forward slashes should be read as one forward slash. For example, if a file is moved from "<code>a/c</code>" to "<code>a/b/c</code>", we can describe this movement by "<code>a/{ => b}/c</code>", meaning the source location was "<code>a/c</code>" and not "<code>a//c</code>".</li>
	<li>The string $A$ is empty or ends with a forward slash, and similarly $D$ is empty or starts with a forward slash.</li>
	<li>Both $B$ and $C$ do not start or end with a forward slash.</li>
</ul>

### 입력 

 <p>The input consists of:</p>

<ul>
	<li>One line containing the source location.</li>
	<li>One line containing the destination location.</li>
</ul>

<p>Both lines will contain at most $10^6$ characters, will not begin or end with a forward slash and will not contain any directory name twice. The two strings are guaranteed to be different.</p>

### 출력 

 <p>Output the shortest replacement string that transforms the source location to the destination, satisfying the above constraints.</p>

