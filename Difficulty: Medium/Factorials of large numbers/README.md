<h2><a href="https://www.geeksforgeeks.org/problems/factorials-of-large-numbers2508/1">Factorials of large numbers</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">Given an integer N, find its factorial.&nbsp;<strong>return a list of integers </strong>denoting the digits that make up the factorial of <strong>N</strong>.</span><br><br><span style="font-size: 18px;"><strong>Example 1:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input: </strong>N = 5
<strong>Output: </strong>[1,2,0]
<strong>Explanation </strong>: 5! = 1*2*3*4*5 = 120</span>
</pre>
<p><span style="font-size: 18px;"><strong>Example 2:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input: </strong>N = 10
<strong>Output: </strong>[3,6,2,8,8,0,0]
<strong>Explanation </strong>:
10! = 1*2*3*4*5*6*7*8*9*10 = 3628800</span></pre>
<p><br><span style="font-size: 18px;"><strong>Your</strong> <strong>Task</strong>:<br>You don't need to read input or print anything.&nbsp;Complete the function</span><span style="font-size: 18px;"><em>&nbsp;factorial()&nbsp;</em>that takes integer <strong>N </strong>as input parameter and returns a <strong>list of integers </strong>denoting the digits that make up the factorial of N.</span></p>
<p><br><span style="font-size: 18px;"><strong>Expected Time Complexity</strong> : O(N<sup>2</sup>)<br><strong>Expected Auxilliary Space</strong> : O(1)</span></p>
<p><br><span style="font-size: 18px;"><strong>Constraints</strong>:<br>1 ≤ N ≤ 1000</span></p></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Morgan Stanley</code>&nbsp;<code>Microsoft</code>&nbsp;<code>Samsung</code>&nbsp;<code>MakeMyTrip</code>&nbsp;<code>MAQ Software</code>&nbsp;<code>Adobe</code>&nbsp;<code>Philips</code>&nbsp;<code>BrowserStack</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>number-theory</code>&nbsp;<code>Strings</code>&nbsp;<code>Combinatorial</code>&nbsp;<code>Data Structures</code>&nbsp;



# Factorial Calculation using Array Multiplication (Dry run for the code)

This project demonstrates a **step-by-step calculation of factorial \( N! \)** using an array-based approach to handle large numbers, which standard data types may not support. Below is a dry run for **\( 7! = 5040 \)**, illustrating each step in detail.

---

## Initial Setup

1. **Initialize `ans` as** `[1]`, which represents the factorial of 1.
2. **Set `carry = 0`** to handle any overflow during multiplication.

---

## Execution Steps

The algorithm iterates over values from **`2` to `N`** (in this case, `7`). In each iteration, it multiplies each digit of `ans` by the current `i` value, updating `ans` and managing the `carry` for large products.

### Step-by-Step Execution for \( 7! \)

#### Iteration 1 (i = 2)

1. **Inner Loop** (`j = 0`):
   - **Calculate**: `x = ans[0] * 2 + carry = 1 * 2 + 0 = 2`.
   - **Update `ans[0] = x % 10 = 2`**, so `ans = [2]`.
   - **Update `carry = x / 10 = 0`**.
2. **Carry Processing**:
   - Since `carry = 0`, nothing is added to `ans`.

---

#### Iteration 2 (i = 3)

1. **Inner Loop** (`j = 0`):
   - **Calculate**: `x = ans[0] * 3 + carry = 2 * 3 + 0 = 6`.
   - **Update `ans[0] = x % 10 = 6`**, so `ans = [6]`.
   - **Update `carry = x / 10 = 0`**.
2. **Carry Processing**:
   - Since `carry = 0`, nothing is added to `ans`.

---

#### Iteration 3 (i = 4)

1. **Inner Loop** (`j = 0`):
   - **Calculate**: `x = ans[0] * 4 + carry = 6 * 4 + 0 = 24`.
   - **Update `ans[0] = x % 10 = 4`**, so `ans = [4]`.
   - **Update `carry = x / 10 = 2`**.
2. **Carry Processing**:
   - Push `carry % 10 = 2` to `ans`, so `ans = [4, 2]`.
   - Update `carry = carry / 10 = 0`.

---

#### Iteration 4 (i = 5)

1. **Inner Loop**:
   - `j = 0`: **Calculate**: `x = ans[0] * 5 + carry = 4 * 5 + 0 = 20`.
     - **Update `ans[0] = x % 10 = 0`**, so `ans = [0, 2]`.
     - **Update `carry = x / 10 = 2`**.
   - `j = 1`: **Calculate**: `x = ans[1] * 5 + carry = 2 * 5 + 2 = 12`.
     - **Update `ans[1] = x % 10 = 2`**, so `ans = [0, 2]`.
     - **Update `carry = x / 10 = 1`**.
2. **Carry Processing**:
   - Push `carry % 10 = 1` to `ans`, so `ans = [0, 2, 1]`.
   - Update `carry = carry / 10 = 0`.

---

#### Iteration 5 (i = 6)

1. **Inner Loop**:
   - `j = 0`: **Calculate**: `x = ans[0] * 6 + carry = 0 * 6 + 0 = 0`.
     - **Update `ans[0] = x % 10 = 0`**, so `ans = [0, 2, 1]`.
     - **Update `carry = x / 10 = 0`**.
   - `j = 1`: **Calculate**: `x = ans[1] * 6 + carry = 2 * 6 + 0 = 12`.
     - **Update `ans[1] = x % 10 = 2`**, so `ans = [0, 2, 1]`.
     - **Update `carry = x / 10 = 1`**.
   - `j = 2`: **Calculate**: `x = ans[2] * 6 + carry = 1 * 6 + 1 = 7`.
     - **Update `ans[2] = x % 10 = 7`**, so `ans = [0, 2, 7]`.
     - **Update `carry = x / 10 = 0`**.
2. **Carry Processing**:
   - Since `carry = 0`, nothing is added to `ans`.

---

#### Iteration 6 (i = 7)

1. **Inner Loop**:
   - `j = 0`: **Calculate**: `x = ans[0] * 7 + carry = 0 * 7 + 0 = 0`.
     - **Update `ans[0] = x % 10 = 0`**, so `ans = [0, 2, 7]`.
     - **Update `carry = x / 10 = 0`**.
   - `j = 1`: **Calculate**: `x = ans[1] * 7 + carry = 2 * 7 + 0 = 14`.
     - **Update `ans[1] = x % 10 = 4`**, so `ans = [0, 4, 7]`.
     - **Update `carry = x / 10 = 1`**.
   - `j = 2`: **Calculate**: `x = ans[2] * 7 + carry = 7 * 7 + 1 = 50`.
     - **Update `ans[2] = x % 10 = 0`**, so `ans = [0, 4, 0]`.
     - **Update `carry = x / 10 = 5`**.
2. **Carry Processing**:
   - Push `carry % 10 = 5` to `ans`, so `ans = [0, 4, 0, 5]`.
   - Update `carry = carry / 10 = 0`.

---

## Final Step

- **Reverse `ans`**: `ans = [5, 0, 4, 0]`, representing **5040**, which is \( 7! \).

---

## Final Output

The output is `[5, 0, 4, 0]`, which represents **\( 7! = 5040 \)**.

This step-by-step guide provides a visualization of the **multiplication and carry management in the array**, making it a practical approach for calculating large factorials in programming.
