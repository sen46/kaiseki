%ネイピア
function yn = z_Euler_e(n)

a = 0;
b = 1;
h = (b - a) / n;

x = a : h : b;
y = zeros(size(x));
y(1) = 1;

for i = 1 : length(x) - 1
    y(i + 1) = y(i) + h * y(i);
end

format shortE
yn = y(n + 1)