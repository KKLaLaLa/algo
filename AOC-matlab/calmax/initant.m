function ants = initant(num, xl, xu, yl, yu)
% 初始化蚁群
% num       input  蚂蚁数量
% xl        input  x最小
% xu        input  x最大
% yl        input  y最小
% yu        input  y最大
% ants      output 蚁群
ants = rand(num, 2);
ants(:,1) = xl + (xu - xl) .* ants(:,1);
ants(:,2) = yl + (yu - yl) .* ants(:,2);