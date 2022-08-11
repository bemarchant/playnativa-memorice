import time
from machine import Pin
from machine import PWM
from machine import ADC
import random
import array
import myaudios

out = Pin(16, Pin.OUT)
adc = ADC(0)
pwm = PWM(Pin(17))


#Methods
def get_audio(sound_number):
    if(sound_number == 1):
        return myaudios.sound1
    elif(sound_number == 2):
        return myaudios.sound2
    elif(sound_number == 3):
        return myaudios.sound3
    elif(sound_number == 4):
        return myaudios.sound4
    elif(sound_number == 5):
        return myaudios.sound5
    elif(sound_number == 6):
        return myaudios.sound6
    
#Classes
class Board:
    def __init__(self):
        self.numberOfButtons = 12
        self.numberOfPlayers = 2
        self.numberOfSounds = 6
        self.buttonOff = Button()
        self.buttonList = []
        self.soundList = []
        self.playerList = []
        
        self.setBoard()
        self.shuffleButtons()
        self.getButtonPushed()
    
    def getButtonPushed(self):
        dV = 3.3/6
        adc_read = adc.read_u16() * 3.3 / 65535
        if(adc_read > 0 and adc_read <  dV):
            return(self.buttonOff)
        elif(adc_read >= dV and adc_read <  2*dV):
            return(self.buttonList[0])
        elif(adc_read >= 2*dV and adc_read <  3*dV):
            return(self.buttonList[1])
        elif(adc_read >= 3*dV and adc_read <  4*dV):
            return(self.buttonList[2])
        elif(adc_read >= 4*dV and adc_read <  5*dV):
            return(self.buttonList[3])
        elif(adc_read >= 5*dV and adc_read <=  6*dV):
            return(self.buttonList[4])
            
    def setPlayers(self):
        playerOne = Player()
        playerTwo = Player()
        playerList = [playerOne,playerTwo]   
    
    def setBoard(self):
        for s in range(self.numberOfSounds):
            sound = Sound()
            sound.name = str(s)
            sound.audio = get_audio(1)

            self.soundList.append(sound)
    
        duplicateSoundList = self.soundList + self.soundList
        
        for b in range(self.numberOfButtons):
            button = Button()
            button.number = b
            button.sound = duplicateSoundList[b]
            self.buttonList.append(button)

        return

    def shuffleButtons(self):        
        for b in range(self.numberOfButtons):
            r = random.randint(0, self.numberOfButtons - 1)
            button0 = self.buttonList[b]
            button1 = self.buttonList[r]
            self.buttonList[b] = button1
            self.buttonList[r] = button0
        return
    
class Sound:
    def __init__(self):
        self.name = ""
        self.info = ""
        self.audio = []
        self.isPlaying = False
        
    def play(self):
        self.isPlaying = True
        while(self.isPlaying):
            for s in self.audio:
                time.sleep_us(60)
                pwm.freq(175000)
                pwm.duty_u16(int(65535 * s / 250))
            self.isPlaying = False
    def stop(self):
        self.isPLaying = False
        return
        
class Button:
    def __init__(self):
        self.sound = Sound()
        self.number = 0
        self.isEnabled = True
    def update():
        return
    
class Player:
    def __init__(self):
        self.score = 0
        self.firstButton = Button()
        self.secondButton = Button()
        self.isPlaying = False
    
    def check_PlayerSoundsHear(self):
        if(self.firstButton == self.secondButton):
            self.score += 1
            self.isPlaying = True
            self.firstButton.isEnabled = False
            self.secondButton.isEnabled = False
        else:
            self.isPlaying = False
        return

board = Board()
for i in board.buttonList:
    print(i.sound)
while (True):
    out.value(1)
    reading = adc.read_u16()
    board.getButtonPushed().sound.play()
    time.sleep(2)
