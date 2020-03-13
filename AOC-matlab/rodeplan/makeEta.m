function eta = makeEta(G)
% 制作启发式因子矩阵（到终点距离倒数，障碍物为0）
% G         input  地形矩阵
% eta       output 启发式因子矩阵
eta = G;
[rn, cn] = size(G);
for i = 1:rn
    for j = 1:cn
        if G(i, j) == 1
            eta(i, j) = 0;
        elseif (i == rn && j == cn)
            eta(i, j) = 1;
        else
            eta(i, j) = 1 / ( (rn-i)^2+(cn-j)^2 )^0.5;
        end
    end
end