a = 1;
b = 2;
n = 100;
h = (b - a) / n;

xi = a;
y = zeros(1, n + 1);
y(1) = 1;

for i = 1 : n
    y(i + 1) = y(i) + h * (y(i) / xi + xi);
    xi = xi + h;
end

format shortE
y(n + 1)