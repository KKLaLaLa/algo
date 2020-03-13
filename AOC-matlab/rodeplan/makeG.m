function G = makeG(rn, cn)
% 制作地形矩阵
% rn        input  地形矩阵函数
% cn        input  地形矩阵函数
% G         output 地形矩阵
G = zeros(rn, cn);
G(1:3, 2) = 1;
G(7:10, 1:5) = 1;
G(5, 3) = 1;
G(1, 4) = 1;
G(1:5, 5) = 1;
G(5:7, 7:9) = 1;