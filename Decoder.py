import math
def decode(bits):
    # varables that will be decoded
    """below is what we want to do this semeter"""
    data = {
    'latitude' : 000.00000, #25 bits
    'longitude' : 000.00000, #23 bits
    'altitude' : 000.00000, # 16 bits
    'temperatureE' : 000, #10
    'temperatureI' : 000, #10
    'signalStrength' : 0, #3 stop here
    'maxG' : 0,
    'PBS' : 0,
    'radio' : (0,0,0,0),
    'GyroscopeFB' : (0,0,0),
    'Accelerometer' : (0,0,0),
    'Magnotometer' : 0,
    'clock' : 0,
    'cutdown' : 26,
    'Pressure' : 0 #mb   
    }
    data['latitude'] = bitsToNum(bits[0:25],1,5)
    data['longitude'] = bitsToNum(bits[25:49],1, 5)
    data['altitude'] = bitsToNum(bits[49:65],0, 2)
    data['temperatureE'] = bitsToNum(bits[65:75])
    data['temperatureI'] = bitsToNum(bits[75:85])
    data['signalStrength'] = bitsToNum(bits[85:88])

    # if differance between radio lat and long and gps lat and long is greater than 100 meters, send error code
    return data
def bitsToNum(bitString, S = 0, desP = 0):
    retVal = int(bitString, 2)
    if(S == 1 and bitString[0] == '1'):
        retVal -= math.pow(2,len(bitString))
    retVal /= math.pow(10, desP)
    return retVal

if __name__ == "__main__":
    print(decode("1010011010111001001110000010001110100110000101010000001001010100001000100010100001110100"))
    #decode("1110101111")
    #decode("1001010000")