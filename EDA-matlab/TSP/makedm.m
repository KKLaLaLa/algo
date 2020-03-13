function dm = makedm(pos)
% 制作距离矩阵
% pos       input  城市坐标
% dm        output 距离矩阵
[~, len] = size(pos);
deltax = repmat(pos(1,:)', 1, len) - repmat(pos(1,:), len, 1);
deltay = repmat(pos(2,:)', 1, len) - repmat(pos(2,:), len, 1);
dm = round((deltax .^ 2 + deltay .^ 2) .^ 0.5);
end