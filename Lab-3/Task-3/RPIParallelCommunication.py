import serial
import time
import csv

if __name__ == '__main__':
    ser = serial.Serial('/dev/ttyUSB0', 9600, timeout=1)
    ser.reset_input_buffer()
    altitudeData = []
    altitudeCSV = "altitudeData.csv"
    
    iteration = 0
    while True:
        data = ser.readline().decode('utf-8').strip()
        altitudeData.append(data)
        print(data)
        iteration += 1
        time.sleep(5/1000)
        if iteration == 501:
            break
        
        
    altitudeData.pop(0)
    with open('altData.csv', 'w') as file:
        writer = csv.writer(file)
        rows = [[data] for data in altitudeData]
        writer.writerows(rows)
    
    ser1 = serial.Serial('/dev/ttyUSB0', 9600, timeout=1)
    ser.reset_input_buffer()
    
    for data in altitudeData:
        encodedData = data.encode('utf-8')
        print(encodedData)
        ser1.write(encodedData)
        time.sleep(100/1000)
    
    print("Done")