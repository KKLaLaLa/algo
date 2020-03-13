function plotobjfun(xl, xu, yl, yu, step)
% 绘制函数图像
% xl        input  x最小值
% xu        input  x最大值
% yl        input  y最小值
% yu        input  y最大值
% step      input  采样距离
[x, y] = meshgrid(xl:step:xu, yl:step:yu);
f = '-(x.^4 + 3*y.^4 - 0.2*cos(3*pi*x) - 0.4*cos(4*pi*y) + 0.6)';
z = eval(f);
mesh(x, y, z);
