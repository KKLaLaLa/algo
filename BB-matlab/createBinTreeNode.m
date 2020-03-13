% createBinTreeNode.m
% ������������ÿһ����Ӧһ��
function BinTree = createBinTreeNode(binTreeNode)

global result;
global lowerBound;
global upperBound;
global count;

if isempty(binTreeNode)
    return;
else
    BinTree{1} = binTreeNode;
    BinTree{2} = [];
    BinTree{3} = [];
    linpp.f = binTreeNode{1};
    linpp.Aineq = binTreeNode{1};
    linpp.biner = binTreeNode{1};
    linpp.Aeq = binTreeNode{1};
    linpp.beq = binTreeNode{1};
    linpp.lb = binTreeNode{1};
    linpp.ub = binTreeNode{1};
    linpp.options = [];
    linpp.solver = 'linprog';
    
    %[x, fval, exitflag] = linprog(linpp);
    [x, fval, exitflag] = linprog(binTreeNode{1}, binTreeNode{2}, binTreeNode{3}, ...
        binTreeNode{4}, binTreeNode{5}, binTreeNode{6}, binTreeNode{7});
    if count == 1
%         upperBound = 0; % ��ʼ�½�Ϊ��
        lowerBound = fval;
        count = 2;
    end
    
    if ~IsInRange(fval)
        return;
    end

    if exitflag == 1
        flag = [];
        % Ѱ�ҷ����������
        for i = 1 : length(x)
            if round(x(i)) ~= x(i)
                flag = i;
                break;
            end
        end
        % ��֧
        if ~isempty(flag)
            lowerBound = max([lowerBound; fval]);
            OutputLowerAndUpperBounds();
            lbnd = binTreeNode{6};
            ubnd = binTreeNode{7};
            lbnd(flag, 1) = ceil(x(flag, 1)); % ����������������
            ubnd(flag, 1) = floor(x(flag, 1));
            
            % ���бȽϣ�����ѡ��Ŀ�꺯���ϴ�Ľ��з�֧
            [~, fval1] = linprog(binTreeNode{1}, binTreeNode{2}, binTreeNode{3}, ...
        binTreeNode{4}, binTreeNode{5}, binTreeNode{6}, ubnd);
            [~, fval2] = linprog(binTreeNode{1}, binTreeNode{2}, binTreeNode{3}, ...
        binTreeNode{4}, binTreeNode{5}, lbnd, binTreeNode{7});
            if fval1 < fval2                
                % ����������          
                BinTree{2} = createBinTreeNode({binTreeNode{1}, binTreeNode{2}, binTreeNode{3}, ...
            binTreeNode{4}, binTreeNode{5}, binTreeNode{6}, ubnd});

                % ����������
                BinTree{3} = createBinTreeNode({binTreeNode{1}, binTreeNode{2}, binTreeNode{3}, ...
            binTreeNode{4}, binTreeNode{5}, lbnd, binTreeNode{7}});
            else
                % ����������
                BinTree{3} = createBinTreeNode({binTreeNode{1}, binTreeNode{2}, binTreeNode{3}, ...
            binTreeNode{4}, binTreeNode{5}, lbnd, binTreeNode{7}});
                % ����������          
                BinTree{2} = createBinTreeNode({binTreeNode{1}, binTreeNode{2}, binTreeNode{3}, ...
            binTreeNode{4}, binTreeNode{5}, binTreeNode{6}, ubnd});
            end
        else
            upperBound = min([upperBound; fval]);
            OutputLowerAndUpperBounds();
            result = [result; [x', fval]];
            return;
        end
    else
        % ��֦
        return;
    end  
end




