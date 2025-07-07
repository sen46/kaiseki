function U = ex01(n, m)

	% 位置の刻み幅
	h = 1 / n;
	% 時間の刻み幅
	k = 1 / m;
	r = k / h ^ 2;
	% n + 1行, m + 1列の行列
	% 位置、時間
	U = zeros(n + 1, m + 1);

	% 時間が0のときの初期条件
	for i = 2 : n
		x = (i - 1) * h;
		U(i, 1) = sin(2 * pi * x);
	end
	U(1, 1) = 0;
	U(n + 1, 1) = 0;

	% t = 0のときは上で初期化済みだからj = 2スタート
	for j = 1 : m
		for i = 1 : n + 1
			if (i == 1 || i == n + 1)
				U(i, j) = 0;
			else
				U(i, j + 1) = r * U(i - 1, j) + (1 - 2 * r) * U(i, j) + r * U(i + 1, j);
			end
		end
	end

	figure(1)
	clf
	plot(linspace(0, 1, n + 1), U(:, m + 1));
	xlabel('x-axis')
	ylabel('y-axis')
