%{
// Flex handles ambiguity by matching longest string;
// in case of tie, it matches the first one.

#include <iostream>
#include <string>
#include <stack>

  std::stack<std::string> stk;
  void mirror();
%}

blank        [ ]

%%

[\n]         mirror(); 
{blank}      stk.push(" ");
a            {  std::string str = u8"\u0250"; stk.push(str); }
b            {  std::string str = u8"\u0071"; stk.push(str); }
c            {  std::string str = u8"\u0254"; stk.push(str); }
d            {  std::string str = u8"\u0070"; stk.push(str); }
e            {  std::string str = u8"\u01DD"; stk.push(str); }
f            {  std::string str = u8"\u025F"; stk.push(str); }
g            {  std::string str = u8"\u0253"; stk.push(str); }
h            {  std::string str = u8"\u0265"; stk.push(str); }
i            {  std::string str = u8"\u0131"; stk.push(str); }
j            {  std::string str = u8"\u027E"; stk.push(str); }
k            {  std::string str = u8"\u029E"; stk.push(str); }
l            {  std::string str = u8"\u006C"; stk.push(str); }
m            {  std::string str = u8"\u026F"; stk.push(str); }
n            {  std::string str = u8"\u0075"; stk.push(str); }
o            {  std::string str = u8"\u006F"; stk.push(str); }
p            {  std::string str = u8"\u0064"; stk.push(str); }
q            {  std::string str = u8"\u0062"; stk.push(str); }
r            {  std::string str = u8"\u0279"; stk.push(str); }
s            {  std::string str = u8"\u0073"; stk.push(str); }
t            {  std::string str = u8"\u0287"; stk.push(str); }
u            {  std::string str = u8"\u006E"; stk.push(str); }
v            {  std::string str = u8"\u028C"; stk.push(str); }
w            {  std::string str = u8"\u028D"; stk.push(str); }
x            {  std::string str = u8"\u0078"; stk.push(str); }
y            {  std::string str = u8"\u028E"; stk.push(str); }
z            {  std::string str = u8"\u007A"; stk.push(str); }
A            {  std::string str = u8"\u2200"; stk.push(str); }
B            {  stk.push("B");  }
C            {  std::string str = u8"\u0186"; stk.push(str); }
D            {  stk.push("D");  }
E            {  std::string str = u8"\u018E"; stk.push(str); }
F            {  std::string str = u8"\u2132"; stk.push(str); }
G            {  std::string str = u8"\u05E4"; stk.push(str); }
H            {  stk.push("H");  }
I            {  stk.push("I");  }
J            {  std::string str = u8"\u017F"; stk.push(str); }
K            {  stk.push("K");  }
L            {  std::string str = u8"\u006C"; stk.push(str); }
M            {  stk.push("W"); }
N            {  stk.push("N"); }
O            {  stk.push("O"); }
P            {  std::string str = u8"\u0500"; stk.push(str); }
Q            {  stk.push("Q"); }
R            {  stk.push("R"); }
S            {  stk.push("S"); }
T            {  std::string str = u8"\u2534"; stk.push(str); }
U            {  std::string str = u8"\u2229"; stk.push(str); }
V            {  std::string str = u8"\u039B"; stk.push(str); }
W            {  stk.push("M"); }
X            {  stk.push("X"); }
Y            {  std::string str = u8"\u2144"; stk.push(str); }
Z            {  stk.push("Z"); }  
0            {  stk.push("0"); }
1            {  std::string str = u8"\u0196"; stk.push(str); }
2            {  std::string str = u8"\u1105"; stk.push(str); }
3            {  std::string str = u8"\u0190"; stk.push(str); }
4            {  std::string str = u8"\u3123"; stk.push(str); }
5            {  std::string str = u8"\u03DB"; stk.push(str); }
6            {  stk.push("9"); }
7            {  std::string str = u8"\u3125"; stk.push(str); }
8            {  stk.push("8"); }
9            {  stk.push("6"); }  
&            {  std::string str = u8"\u214B"; stk.push(str); }
_            {  std::string str = u8"\u203E"; stk.push(str); }
\?           {  std::string str = u8"\u00BF"; stk.push(str); }
!            {  std::string str = u8"\u00A1"; stk.push(str); }
\"           {  std::string str = u8"\u201E"; stk.push(str); }
\'           {  std::string str = u8"\u002C"; stk.push(str); }
\.           {  std::string str = u8"\u02D9"; stk.push(str); }
,            {  std::string str = u8"\u0027"; stk.push(str); }
;            {  std::string str = u8"\u061B"; stk.push(str); }         
.            { }
%%

int yywrap() { 
  yylex_destroy();
  return 1; 
}

void mirror() {
  std::string text;
  while (!stk.empty()) {
    text += std::string(stk.top());
    stk.pop();
  }
  std::cout << text << std::endl;
}