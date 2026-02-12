// Program to check if a string's parentheses/brackets/braces
// are correctly balanced.
//
// Milod Kazerounian, Tufts University, Fall 2021.
// with some gentle editing for display width by Mark A. Sheldon, Fall 2024

#include <iostream>
#include <stack>

using namespace std;

bool is_balanced(string expr);
bool is_opener(char c);
bool is_closer(char c);
bool matches(char opener, char closer);
void print_result(string expr);

int main()
{
    print_result("(2 + 2)");
    print_result("([]{[()]{}}())");
    print_result("}");
    print_result("(}");
    print_result("((])");
    return 0;
}

/* Input: string expr.
 * Calls is_balanced, and returns a message indicating
 * whether given expr is balanced or not.
 */
void print_result(string expr)
{
    if (is_balanced(expr)) {
        cout << "Expression " << expr << " is well-balanced.\n";
    }
    else {
        cout << "Expression " << expr << " is NOT well-balanced.\n";
    }
}

/* Input: character c.
 * Output: true if c is one of (, [, or {, false otherwise.
 */
bool is_opener(char c)
{
    return (c == '(') or (c == '[') or (c == '{');
}

/* Input: character c.
 * Output: true if c is one of ), ], or }, false otherwise.
 */
bool is_closer(char c)
{
    return (c == ')') or (c == ']') or (c == '}');
}

/* Input: char opener is one of (, [, or {,
 *        char closer is one of ), ], or }.
 * Output: true if opener matches closer, false otherwise.
 */
bool matches(char opener, char closer)
{
    return ((opener == '(') and (closer == ')'))
        or ((opener == '{') and (closer == '}'))
        or ((opener == '[') and (closer == ']'));
}

/* Input: String that may include "(",")", "[","]", "{", and "}".
 *        Note that it can include other characters too.
 * Output: true parens/brackets/braces are balanced in expr,
 *         false otherwise.
 */
bool is_balanced(string expr)
{
    // Declare a stack of characters.
    stack<char> paren_stack;

    // I'm using a for loop to iterate over expr, but we
    // could easily convert this to a while loop that runs
    // as long as there are characters left in expr.
    for (size_t i = 0; i < expr.length(); i++) {
        char curr_char = expr[i];
        if (is_opener(curr_char)) {
            paren_stack.push(curr_char);
        }
        else if (is_closer(curr_char)) {
            if (paren_stack.empty()
		or not matches(paren_stack.top(), curr_char)) {
                // If either of above conditions is true, no need to look at
                // rest of the string: we know expr is not balanced.
                return false;
            }
            else {
                // Matched closer with opener on top of stack, so
                // pop top of stack since we're done with this subexpression.
                paren_stack.pop();
            }
        }
        else {
            // If curr_char is anything else, then it doesn't affect whether
            // or not the parentheses are balanced.  Just continue.
            continue;
        }
    }

    if (not paren_stack.empty()) {
        // If we went over the whole expr and the stack is not empty,
        // then there must be some openers that were not matched.
        return false;
    }
    else {
        return true;
    }
}