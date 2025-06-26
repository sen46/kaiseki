function [x, y] = z_EulerSystem(n)

h = 0.1;
a = 0;
b = h * n;
t = a : h : b;
x = zeros(size(t));
y = zeros(size(t));
x(1) = 10;
y(1) = 5;

for i = 1 : length(t) - 1
	x(i + 1) = x(i) + h * (x(i) - (x(i) * y(i)) / 2);
	y(i + 1) = y(i) + h * ((x(i) * y(i)) / 8 - y(i) / 2);
end

figure(1)
plot(x, y, '-o')
xlabel('x-axis')
ylabel('y-axis')
