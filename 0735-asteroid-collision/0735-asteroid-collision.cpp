class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for (auto asteroid : asteroids) {

            bool alive = true;   // Indicates whether the current asteroid survives

            // Collision is possible only when:
            // stack top is moving right (+ve) and current asteroid is moving left (-ve)
            while (!st.empty() && st.top() > 0 && asteroid < 0) {

                // Current asteroid is smaller, so it explodes
                if (st.top() > abs(asteroid)) {
                    alive = false;
                    break;
                }

                // Both asteroids are of the same size, so both explode
                else if (st.top() == abs(asteroid)) {
                    st.pop();
                    alive = false;
                    break;
                }

                // Current asteroid is larger, so the stack top explodes.
                // Continue checking because the current asteroid may collide
                // with more previous asteroids.
                else {
                    st.pop();
                }
            }

            // Push the current asteroid only if it survives all collisions
            if (alive)
                st.push(asteroid);
        }

        vector<int> ans(st.size());

        // Stack contains the surviving asteroids in reverse order,
        // so fill the answer array from back to front.
        for (int i = st.size() - 1; i >= 0; i--) {
            ans[i] = st.top();
            st.pop();
        }

        return ans;
    }
};