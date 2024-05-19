import pandas as pd
import matplotlib.pyplot as plt
from scipy.signal import find_peaks
from scipy.signal import medfilt

from scipy.signal import butter, filtfilt

# Load the CSV file
df = pd.read_csv("/home/nestor/Downloads/bme/dataset/physionet.org/files/pulse-transit-time-ppg/1.1.0/csv/reversed/reversed_s16_sit.csv")
pleth_channels = ['pleth_2']

# Define the range to display (from 0 to 2000)
start_index = 0
end_index = 1500

# Normalize the data for each 'pleth' channel to start from zero
for channel in pleth_channels:
    normalized_data = df[channel][start_index:end_index] - df[channel][start_index]  # Normalize data
    # plt.plot(normalized_data, label=channel)

# plt.xlabel('Time')
# plt.ylabel('Amplitude - Baseline')
# plt.title('Normalized Pleth Channels Data (0 to 2000)')
# plt.legend()

# Apply median filter to the normalized data
filtered_data = medfilt(normalized_data, kernel_size=3)  # Adjust kernel size as needed


peaks, _ = find_peaks(filtered_data, distance=60)


# height : number or ndarray or sequence, optional
#         Required height of peaks. Either a number, ``None``, an array matching
#         `x` or a 2-element sequence of the former. The first element is
#         always interpreted as the  minimal and the second, if supplied, as the
#         maximal required height.
#     threshold : number or ndarray or sequence, optional
#         Required threshold of peaks, the vertical distance to its neighboring
#         samples. Either a number, ``None``, an array matching `x` or a
#         2-element sequence of the former. The first element is always
#         interpreted as the  minimal and the second, if supplied, as the maximal
#         required threshold.
#     distance : number, optional
#         Required minimal horizontal distance (>= 1) in samples between
#         neighbouring peaks. Smaller peaks are removed first until the condition
#         is fulfilled for all remaining peaks.
#     prominence : number or ndarray or sequence, optional
#         Required prominence of peaks. Either a number, ``None``, an array
#         matching `x` or a 2-element sequence of the former. The first
#         element is always interpreted as the  minimal and the second, if
#         supplied, as the maximal required prominence.
#     width : number or ndarray or sequence, optional
#         Required width of peaks in samples. Either a number, ``None``, an array
#         matching `x` or a 2-element sequence of the former. The first
#         element is always interpreted as the  minimal and the second, if
#         supplied, as the maximal required width.
#     wlen : int, optional
#         Used for calculation of the peaks prominences, thus it is only used if
#         one of the arguments `prominence` or `width` is given. See argument
#         `wlen` in `peak_prominences` for a full description of its effects.
#     rel_height : float, optional
#         Used for calculation of the peaks width, thus it is only used if `width`
#         is given. See argument  `rel_height` in `peak_widths` for a full
#         description of its effects.
#     plateau_size : number or ndarray or sequence, optional
#         Required size of the flat top of peaks in samples. Either a number,
#         ``None``, an array matching `x` or a 2-element sequence of the former.
#         The first element is always interpreted as the minimal and the second,
#         if supplied as the maximal required plateau size.

# plt.figure(figsize=(12, 6))
plt.plot(filtered_data, label='Filtered Data')
plt.xlabel('Time')
plt.ylabel('Amplitude - Baseline')
plt.title('Pleth Channels Data after Median Filtering')
plt.legend()
plt.plot(peaks, filtered_data[peaks], 'ro', label='Peaks')
plt.legend()
# plt.show(block=False)
plt.show()
# plt.pause(2)  # Display for 32 seconds
plt.close()

