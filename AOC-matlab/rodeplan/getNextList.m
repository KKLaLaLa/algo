function nextlist = getNextList(point, rn, cn, D)
% 给出待选点列表
% point         input  当前点
% rn            input  地图行数
% cn            input  地图列数
% D             input  禁忌地图
% nextlist      output 待选点列表
list = find(D);
nextlist = zeros(1, length(list)+1);
[pointx, pointy] = ind2sub([rn, cn], point);
for i = 1:length(list)
    [indexx, indexy] = ind2sub([rn, cn], list(i));
    if (indexx >= pointx-1 && indexx <= pointx+1 ...
            && indexy >= pointy-1 && indexy <= pointy+1)
        nextlist(1, 1) = nextlist(1, 1) + 1;
        nextlist(1, nextlist(1,1)+1) = list(i);
    end
end
a  = nextlist(1,1);
nextlist = nextlist(1, 2:1+a);