function fitvalue = calfitvalue(objvalue, opt)
% 根据目标函数值生成适应度值，需根据实际情况重写
% objvalue      input  目标函数值
% opt           input  操作模式，指定为'min'或'max'
% fitvalue      output 适应度值
fitvalue = zeros(size(objvalue,1), 1);
for i = 1 : size(objvalue, 1)
    if strcmp(opt, 'min')
        if objvalue(i) < 0
            temp = -objvalue(i);
        else
            temp = 0;
        end
    else
        if objvalue(i) > 0
            temp = objvalue(i);
        else
            temp = 0;
        end
    end
    fitvalue(i) = temp;
end
fitvalue = fitvalue'; %矩阵转制
end