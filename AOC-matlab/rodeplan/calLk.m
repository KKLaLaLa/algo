function lk = calLk(npath, rn, cn)
% 计算路径长度
% npath         input  路径
% rn            input  地图行数
% cn            input  地图列数
% lk            output 路径长度 rnx1
[nr, ~] = size(npath);
lk = zeros(nr, 1);
for i = 1:nr
    path = npath(i, 2:1+npath(1,1));
    for j = 2:length(path)
        [x1, y1] = ind2sub([rn, cn], path(j-1));
        [x2, y2] = ind2sub([rn, cn], path(j));
        lk(i) = lk(i) + ((x2-x1)^2+(y2-y1)^2)^0.5;
    end
end
end