import os
import pandas as pd

# Path to the directory containing CSV files
directory = "/home/nestor/Downloads/bme/dataset/physionet.org/files/pulse-transit-time-ppg/1.1.0/csv"
output_directory = "/home/nestor/Downloads/bme/dataset/physionet.org/files/pulse-transit-time-ppg/1.1.0/csv/reversed/"

# Create output directory if it doesn't exist
if not os.path.exists(output_directory):
    os.makedirs(output_directory)

# Loop through all CSV files in the directory
for filename in os.listdir(directory):
    if filename.endswith(".csv"):
        # Load the original CSV file
        df = pd.read_csv(os.path.join(directory, filename))
        
        # Reverse the order of rows
        df_reversed = df.iloc[::-1]
        
        # Save the reversed DataFrame to a new CSV file in the output directory
        output_filename = "reversed_" + filename
        df_reversed.to_csv(os.path.join(output_directory, output_filename), index=False)

print("All CSV files in the directory have been successfully reversed and saved.")
