%cut -d ' ' -f 2-4 groundtruth.txt >output_ground_truth.txt 用shell命令直接在命令行里打
% cut -d ' ' -f 2-5 Fr1xyzcamera_pose_FOVISJan11Trial1.txt >fovisJan11Trial1.txt
%python associate.py rgb.txt depth.txt >associatedData.txt


fid1 = fopen('associatedDataFinal.txt');
C = textscan(fid1, '%s %s %s %s');


N = size(C{1}, 1);
index = [1:N];


M=cell2mat(C{1});
M1=cell2mat(C{2});
M2=cell2mat(C{4});



fid2 = fopen('outputAssociatedData.txt', 'w');
for i = [1:N]
    fprintf(fid2, '%d %s %s\n', index(i), M1(i,:), M2(i,:));
end

fclose(fid1);
fclose(fid2);
