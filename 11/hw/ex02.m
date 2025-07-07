n = 6;
h = 1 / 6;
A = zeros(n - 1, n - 1);
b = zeros(n - 1, 1);

for i = 1 : n - 1
	for j = 1 : n - 1
		if (i == j)
			A(i, j) = -2;
		elseif (i == j + 1)
			A(i, j) = 2 / 3;
		elseif (i + 1 == j)
			A(i, j) = 4 / 3;
		else
			A(i, j) = 0;
        end
	end
end

for i = 1 : n - 2
	b(i) = 1 / 18;
end
b(n - 1) = -23 / 18;

y = A \ b;

fprintf("%.4e\n", y(2));
