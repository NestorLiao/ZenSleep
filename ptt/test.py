import pandas as pd

# 读取包含参与者信息的CSV文件
df_subjects_info = pd.read_csv("files/pulse-transit-time-ppg/1.1.0/csv/subjects_info.csv")


# 打印出每个参与者的起始和结束时的收缩压和舒张压
for index, row in df_subjects_info.iterrows():
    # print(f"Participant: {row['filename']}")
    print(f"Start Sys BP: {row['bp_sys_start']} mmHg, Start Dia BP: {row['bp_dia_start']} mmHg")
    print(f"End Sys BP: {row['bp_sys_end']} mmHg, End Dia BP: {row['bp_dia_end']} mmHg")
    print()
