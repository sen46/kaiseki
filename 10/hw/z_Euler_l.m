% ロジスティック
function z_Euler_l(n)

a = 0;
T = 8;
h = (T - a) / n;
K = 10;
r = 2;

t = a : h : T;
u = zeros(size(t));
u(1) = 1;

for i = 1 : length(t) - 1
    u(i + 1) = u(i) + h * (r * u(i) * (1 - (u(i) / K)));
end

un = u(n + 1);

tr = K / (1 + (K / u(1) - 1) * exp(-r * T));
error = abs(tr - un);
%出力
fprintf('n = %d\n', n);
fprintf('h（刻み幅） :  %.4e\n', h);
if (n == 100)
    fprintf('u(T) の近似値 : %.15e\n', un);
end
fprintf('残差（誤差） : %.4e\n', error);