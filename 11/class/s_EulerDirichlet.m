function s_EulerDirichlet(n)
a = 0;
b = 1;
h = 0.01;
N = (b - a) / h;
x = a : h : b;
r = -pi ^ 2 * sin(pi * x);
alpha = 0;
beta = 0;
A = zeros(N - 1);
w = zeros(N - 1, 1);
for i = 1 : N - 1
	for j = 1 : N - 1
		if (i == j)
			A(i, j) = -2;
        elseif (abs(i - j) == 1)
			A(i, j) = 1;
        else
			A(i, j) = 0;
		end
	end
end

for i = 1 : N - 2
	w(i) = h * h * r(i);
end

w(N - 1) = 0;

y = A \ w;
y = vertcat(alpha, y, beta)

figure(1)
plot(x, y, '-o')
xlabel('x-axis')
ylabel('y-axis')
