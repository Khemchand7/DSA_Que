<h2><a href="https://www.geeksforgeeks.org/problems/minimum-swaps-required-to-bring-all-elements-less-than-or-equal-to-k-together4847/1">Minimum swaps and K together</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 14pt;">Given an array <strong>arr</strong>&nbsp;and a number <strong>k</strong>. One can apply a swap operation on the array any number of times, i.e choose any two index i and j&nbsp;(i &lt; j) and swap arr[i] , arr[j] . Find the&nbsp;<strong>minimum</strong>&nbsp;number of swaps required to bring all the numbers less than or equal to&nbsp;<strong>k</strong>&nbsp;together, i.e. make them a contiguous&nbsp;subarray.</span></p>
<p><span style="font-size: 14pt;"><strong>Examples :</strong></span></p>
<pre><span style="font-size: 14pt;"><strong>Input:</strong> arr[] = [2, 1, 5, 6, 3], k = 3
<strong>Output:</strong> 1
<strong>Explanation: </strong>To bring elements 2, 1, 3 together, swap index 2 with 4 (0-based indexing), i.e. element arr[2] = 5 with arr[4] = 3 such that final array will be- arr[] = [2, 1, 3, 6, 5]
</span></pre>
<pre><span style="font-size: 14pt;"><strong>Input:</strong> arr[] = [2, 7, 9, 5, 8, 7, 4], k = 6 <strong>
Output:</strong> 2 
<strong>Explanation:</strong> To bring elements 2, 5, 4 together, swap index 0 with 2 (0-based indexing) and index 4 with 6 (0-based indexing) such that final array will be- arr[] = [9, 7, 2, 5, 4, 7, 8]<br></span></pre>
<pre><span style="font-size: 14pt;"><strong>Input:</strong> arr[] = [2, 4, 5, 3, 6, 1, 8], k = 6 <strong>
Output:</strong> 0</span></pre>
<p><span style="font-size: 14pt;"><strong>Constraints:</strong></span><br style="font-size: 18.6667px;"><span style="font-size: 14pt;">1 ≤ arr.size() ≤ 10<sup>6</sup></span><br style="font-size: 18.6667px;"><span style="font-size: 14pt;">1 ≤ arr[i] ≤ 10<sup>6</sup></span><br style="font-size: 18.6667px;"><span style="font-size: 14pt;">1 ≤ k ≤ 10<sup>6</sup></span></p></div><br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Arrays</code>&nbsp;<code>Data Structures</code>&nbsp;<code>prefix-sum</code>&nbsp;<code>sliding-window</code>&nbsp;