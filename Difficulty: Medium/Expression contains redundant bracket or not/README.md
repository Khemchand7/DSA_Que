<h2><a href="https://www.geeksforgeeks.org/problems/expression-contains-redundant-bracket-or-not/0">Expression contains redundant bracket or not</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">Given a string of balanced expression <strong>str</strong>, find if it contains a redundant parenthesis or not. A set of parenthesis are redundant if the same sub-expression is surrounded by unnecessary or multiple brackets. Return <strong>1</strong> if</span><span style="font-size: 18px;">it contains a redundant parenthesis</span><span style="font-size: 18px;">, else <strong>0</strong>.<br></span><span style="font-size: 18px;"><strong>Note:</strong>&nbsp;Expression may contain <strong>+ , - ,&nbsp;*,</strong> and<strong> /</strong> operators. Given expression is&nbsp;<strong>valid</strong>&nbsp;and there are&nbsp;<strong>no white</strong>&nbsp;spaces present.</span><br><br><span style="font-size: 18px;"><strong>Example 1:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input:
</strong>exp = ((a+b))</span><span style="font-size: 18px;">
<strong>Output:
</strong>Yes
<strong>Explanation:</strong>
((a+b)) can reduced to (a+b).
</span></pre>
<p><span style="font-size: 18px;"><strong>Example 2:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input:</strong>
exp = (a+b+(c+d))</span><span style="font-size: 18px;">
<strong>Output:</strong>
No
<strong>Explanation:</strong>
(a+b+(c+d)) doesn't have any redundant or multiple
brackets.</span></pre>
<p><span style="font-size: 18px;"><strong>Your task:<br></strong></span><span style="font-size: 18px;">You don't have to read input or print anything. Your task is to complete the function <strong>checkRedundancy</strong></span><span style="font-size: 18px;"><strong>()</strong> which takes the string <strong>s</strong> as input and returns <strong>1</strong> if&nbsp;it contains redundant parentheses else <strong>0</strong>.</span></p>
<p><span style="font-size: 18px;"><strong>Constraints:<br></strong></span><span style="font-size: 18px;">1&lt;=|str|&lt;=10<sup>4</sup></span></p>
<p><span style="font-size: 18px;"><strong>Expected Time Complexity:</strong>&nbsp;O(N)<br></span><span style="font-size: 18px;"><strong>Expected Auxiliary Space:&nbsp;</strong>O(N)</span></p></div><br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Stack</code>&nbsp;<code>Strings</code>&nbsp;