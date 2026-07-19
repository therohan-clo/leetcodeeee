class Solution {
public:
    bool isValid(std::string s) {
        // A stack to keep track of expected closing brackets
        std::stack<char> bracketStack;
        
        for (char c : s) {
            // If it's an opening bracket, push the expected closing bracket onto the stack
            if (c == '(') {
                bracketStack.push(')');
            } else if (c == '{') {
                bracketStack.push('}');
            } else if (c == '[') {
                bracketStack.push(']');
            } 
            // If it's a closing bracket, check if it matches the top of the stack
            else {
                if (bracketStack.empty() || bracketStack.top() != c) {
                    return false;
                }
                bracketStack.pop(); // Match found, remove it
            }
        }
        
        // If the stack is empty, all brackets were correctly matched
        return bracketStack.empty();
    }
};