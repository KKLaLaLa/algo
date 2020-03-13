rn = 10; cn = 10;
G       = makeG(rn, cn);                % 地形图
tau     = 8 .* ones(rn, cn);            % 初始化信息素
MaxGen  = 100;                          % 迭代次数
N       = 50;                           % 蚂蚁个数
S       = 1;            % 路径起始点
E       = rn * cn;      % 路径终点
Alpha   = 1;            % 信息素重要程度
Beta    = 30;           % 启发式因子重要程度
Rho     = 0.3;          % 信息素挥发系数
Q       = 5;            % 信息素增加系数

Eta     = makeEta(G);   % 距离倒数矩阵

gpath = zeros(MaxGen, rn*cn+1);     % 每代最优路径 [地点个数 地点……]

for g = 1:MaxGen
    npath = zeros(N, rn*cn+1);          % 每个路径 [地点个数 地点……]
    for n = 1:N
        D = Eta;                        % 禁忌矩阵
        path = zeros(1, rn*cn+1);       % 路径

        % 更新点、路径和禁忌矩阵
        point = S;
        path(1, 1) = path(1, 1) + 1;
        path(1, path(1,1)+1) = point;
        D(point) = 0;

        % 搜索下一个点的坐标范围
        nextlist = getNextList(point, rn, cn, D);
        % 一直前进，直到到达食物或者陷入死胡同
        while point ~= E && ~isempty(nextlist)
            % 轮盘赌算法取下一点
            p = zeros(1, length(nextlist));
            for i = 1:length(nextlist)
                p(1, i) = (tau(nextlist(i))^Alpha) * (Eta(nextlist(i))^Beta);
            end
            nextpoint = nextlist(getNextPoint(p));

            % 更新点、路径和禁忌矩阵
            point = nextpoint;
            path(1, 1) = path(1, 1) + 1;
            path(1, path(1,1)+1) = point;
            D(point) = 0;
            nextlist = getNextList(point, rn, cn, D);
        end
        % 记录成功成功到达终点的蚂蚁的路径
        if (path(1, 1+path(1,1)) == E)
            npath(n, :) = path;
        end
    end
    npath = npath(find(sum(npath,2)), :);       % 保留到达终点的路径
    lk = calLk(npath, rn, cn);                  % 计算lk距离
    % 更新信息素
    tau = (1 - Rho) .* tau;
    for i = 1:size(npath, 1)
        for j = 2:npath(i,1)+1
            tau(npath(i,j)) = tau(npath(i,j)) + Q / lk(i);
        end
    end
    [~, minindex] = min(lk);
    if size(npath, 1) > 0
        gpath(g, :) = npath(minindex, :); 
    end
end
lk = calLk(npath, rn, cn);
[minvalue, minindex] = min(lk);
fprintf("min length: %f\n", minvalue);
bestpath = gpath(minindex,:);
bestpath = bestpath(2:1+bestpath(1,1));
figure;
imagesc(G);
hold on;
for i = 2:length(bestpath)
    [x1, y1] = ind2sub([rn, cn], bestpath(i-1));
    [x2, y2] = ind2sub([rn, cn], bestpath(i));
    plot([y1, y2], [x1, x2], 'r');
    hold on;
end