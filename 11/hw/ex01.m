function ex01(n)
h = 1 / n;
a = 0;
b = 1;
t = a : h : b;
x = zeros(size(t));
y = zeros(size(t));
x(1) = 1;
y(1) = 0;

for i = 1 : length(t) - 1
	x(i + 1) = x(i) + h * (-4 * x(i) + 2);
	y(i + 1) = y(i) + h * (x(i));
end

fprintf("%.4e\n", y(n + 1));
