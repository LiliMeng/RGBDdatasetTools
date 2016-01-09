fid1 = fopen('Completetimestampfr1desk2.txt');
C = textscan(fid1, '%s');

M=cell2mat(C{1});

index=test(:,1);
timestamp=test(:,2);


fid2 = fopen('outputMatchedTimestamp1.txt', 'w');
test1 = xlsread('keyframe.xlsx', 'A1:M453');
keyframeIndex=test1(:,1);

N1=size(index,1);
N2=size(keyframeIndex,1);

for j=[1:N1]
    for i=[1:N2]
        if index(j,:)==keyframeIndex(i,:)
            fprintf(fid2,'%s\n',M(j,:))
        end
    end
end

% 截取txt文档 awk '{print $1}' associatedData.txt > timestamp.txt
