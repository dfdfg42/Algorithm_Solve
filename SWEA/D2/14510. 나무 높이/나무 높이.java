import java.util.Scanner;

class Solution {
    public static void main(String args[]) throws Exception {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();

        for (int test_case = 1; test_case <= T; test_case++) {
            int N = sc.nextInt();
            int[] trees = new int[N];
            int maxTree = 0;

            for (int i = 0; i < N; i++) {
                trees[i] = sc.nextInt();
                maxTree = Math.max(maxTree, trees[i]);
            }

            // 목표 높이가 maxTree일 때와 maxTree + 1일 때 중 최소값 선택
            long result = Math.min(solve(trees, maxTree), solve(trees, maxTree + 1));

            System.out.println("#" + test_case + " " + result);
        }
    }

    static long solve(int[] trees, int target) {
        long cnt1 = 0;
        long cnt2 = 0;

        for (int h : trees) {
            int diff = target - h;
            cnt2 += diff / 2;
            cnt1 += diff % 2;
        }

        // 2의 개수가 너무 많으면 2 하나를 1 두 개로 쪼개서 균형을 맞춤
        // 1이 2보다 많아지기 직전까지만 쪼개는 것이 핵심
        if (cnt2 > cnt1) {
            long diff = (cnt2 - cnt1) / 3;
            cnt2 -= diff;
            cnt1 += diff * 2;
            
            // 한 번 더 쪼갤 수 있는지 확인 (나머지 처리)
            if (cnt2 - cnt1 == 2) {
                cnt2--;
                cnt1 += 2;
            }
        }

        // 최종 날짜 계산
        if (cnt1 > cnt2) {
            return cnt1 * 2 - 1;
        } else if (cnt2 > cnt1) {
            return cnt2 * 2;
        } else {
            return cnt1 * 2;
        }
    }
}