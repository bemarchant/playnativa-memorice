import time
from machine import Pin
from machine import PWM
from machine import ADC
import random
import array
import myaudios


led = Pin(25, Pin.OUT)
out0 = Pin(16, Pin.OUT)
out1 = Pin(15, Pin.OUT)
adc0 = ADC(0)
adc1 = ADC(1)
pwm = PWM(Pin(17))
pwm_background = PWM(Pin(14))

playerList = []

#Methods
def get_audio(sound_number):
    
    if(sound_number == 1):
        return myaudios.sound1
    
    if(sound_number == 2):
        return myaudios.sound2
    
    if(sound_number == 3):
        return myaudios.sound3
    
    if(sound_number == 4):
        return myaudios.sound4
    
    if(sound_number == 5):
        return myaudios.sound5
    
    if(sound_number == 6):
        return None

def get_PlayerPlaying():
    
    for player in playerList:
        if player.isPlaying:
            return player
            break
        else:
            continue
        
    return None

#Classes
class Game:
    def __init__(self):

        #Game atributes
        self.numberOfButtons = 12
        self.numberOfPlayers = 2
        self.numberOfSounds = 6
        self.buttonOff = Button()
        
        #Game list of objects (Button, Sound, Player)
        self.buttonList = []
        self.soundList = []
        
        self.playerOne = Player()
        self.playerTwo = Player()
        self.playerOne.name = "playerOne"
        self.playerTwo.name = "playerTwo"
        self.playerOne.isPlaying = True
        self.playerTwo.isPlaying = False
        
        #Game methods
        self.set_Game()
        self.shuffleSounds()
        self.get_ButtonPushed()

        #Game status
        self.game_is_over = False
    
    def get_ButtonPushed(self):
        dV = 3.3/self.numberOfSounds
        
        adc_read0 = adc0.read_u16() * 3.3 / 65535
        adc_read1 = adc1.read_u16() * 3.3 / 65535
        
        #No button has been pushed
        if((adc_read0 > 0 and adc_read0 <  dV) and (adc_read1 > 0 and adc_read1 <  dV)):
            return None
        
        print("adc_0 : " + str(adc_read0))
        print("adc_1 : " + str(adc_read1))
        
        if(adc_read0 >= dV and adc_read0 <  2*dV):
            return(self.buttonList[0])
        
        if(adc_read0 >= 2*dV and adc_read0 <  3*dV):
            return(self.buttonList[1])
        
        if(adc_read0 >= 3*dV and adc_read0 <  4*dV):
             return(self.buttonList[2])
        
        if(adc_read0 >= 4*dV and adc_read0 <  5*dV):
             return(self.buttonList[3])
        
        if(adc_read0 >= 5*dV and adc_read0 <=  6*dV):
             return(self.buttonList[4])
            
        if(adc_read1 >= dV and adc_read1 <  2*dV):
            return(self.buttonList[5])
        
        if(adc_read1 >= 2*dV and adc_read1 <  3*dV):
            return(self.buttonList[6])
        
        if(adc_read1 >= 3*dV and adc_read1 <  4*dV):
             return(self.buttonList[7])
        
        if(adc_read1 >= 4*dV and adc_read1 <  5*dV):
             return(self.buttonList[8])
        
        if(adc_read1 >= 5*dV and adc_read1 <=  6*dV):
             return(self.buttonList[9])
   
    def set_Game(self):
        
        playerList.append(self.playerOne)
        playerList.append(self.playerTwo)
        
        for s in range(self.numberOfSounds):
            sound = Sound()
            sound.name = str(s)
            sound.audio = get_audio(s)
            self.soundList.append(sound)
    
        #Duplicate list of sounds
        self.soundList += self.soundList
        self.shuffleSounds()
        
        for b in range(self.numberOfButtons):
            button = Button()
            button.number = b
            button.sound = self.soundList[b]
            self.buttonList.append(button)

        return

    def shuffleSounds(self):        
        for b in range(self.numberOfButtons):
            r = random.randint(0, self.numberOfButtons - 1)
            sound0 = self.soundList[b]
            sound1 = self.soundList[r]
            self.soundList[b] = sound1
            self.soundList[r] = sound0
        return
    
    def checkGameStatus(self):
        self.game_is_over = (sum(b.isEnabled for b in self.buttonList) == 0)
        return

    def startGame(self):
        
        while (not self.game_is_over):
            out0.value(1)
            out1.value(1)
            
            player = get_PlayerPlaying()
            
            buttonPushed = self.get_ButtonPushed()
            
            if(buttonPushed == player.firstButton):
                buttonPushed = None
            if(buttonPushed == player.secondButton):
                buttonPushed = None
            
            if(buttonPushed != None):
                led.value(0)
                buttonPushed.play()
                if(player.firstButton == None):
                    player.firstButton = buttonPushed
                    print("firstButton.sound :" + str(player.firstButton.sound))
                
                elif(player.firstButton != None and player.secondButton == None):
                    player.secondButton = buttonPushed
                    print("secondButton.sound :" + str(player.secondButton.sound))
                
                time.sleep(0.5)
            
            else:
                #do nothing
                led.value(1)
                
                if(get_PlayerPlaying() != None):
                    get_PlayerPlaying().check_ContinuePlaying()
                    time.sleep(0.5)

        return
    
class Sound:
    def __init__(self):
        self.name = ""
        self.info = ""
        self.audio = []
        self.isPlaying = False
        
class Button:
    def __init__(self):
        self.sound = Sound()
        self.number = 0
        self.isEnabled = True
        self.isRinging = True
    
    def update():
        return
    
    def play(self):
        self.isRinging = True
        adc_read0 = adc0.read_u16() * 3.3 / 65535
        adc_read1 = adc1.read_u16() * 3.3 / 65535

        while(self.isRinging and (adc_read0 > 0.2 or adc_read1 > 0.2)):
            for s in self.sound.audio:
                adc_read0 = adc0.read_u16() * 3.3 / 65535
                adc_read1 = adc1.read_u16() * 3.3 / 65535
                time.sleep_us(10)
                pwm.freq(175000)
                try:
                    if((adc_read0 > 0.2 or adc_read1 > 0.2)):
                        pwm.duty_u16(int(65535 * s / 250))
                        continue
                    else:
                        self.isRinging = False
                        break

                except:
                    break
                    print(s)

            self.isRinging = True
        return

    def stop():
        return
    
class Player:
    
    def __init__(self):
        self.score = 0
        self.firstButton = None
        self.secondButton = None
        self.isPlaying = False
        self.name = ""
    
    def check_ContinuePlaying(self):
        
        if (not self.isPlaying):
            return
        
        if (self.firstButton == None and self.secondButton == None):
            print("waiting for " + self.name)
            return
        
        if( self.firstButton != None and self.secondButton == None):
            print("waiting for " + self.name + ' second button')
            return
        
        if(self.secondButton != None and self.firstButton.sound == self.secondButton.sound):
            self.score += 1
            self.firstButton.isEnabled = False
            self.secondButton.isEnabled = False
            self.firstButton = None
            self.secondButton = None
            print("player "+ self.name + " found something!, score: " + str(self.score))
            print("player "+ self.name + " keep looking")
            return
            
        if(self.secondButton != None and self.firstButton.sound != self.secondButton.sound):
            print("player "+ self.name + ", pay more attention")
            self.firstButton = None
            self.secondButton = None
            
            #switch player playing
            for player in playerList:
                player.isPlaying = not player.isPlaying
            
            print(get_PlayerPlaying().name + ' is now your turn')
            return

game = Game()
game.startGame()
