# import time
import random
import array
# from machine import PWM
# from machine import ADC

#Methods

#Arrays
sounds = array.array("b", [0,1,2])
#Classes
class Board:
    def __init__(self):
        self.numberOfButtons = 20
        self.numberOfPlayers = 2
        self.numberOfSounds = 10

        self.buttonList = []
        self.soundList = []
        self.playerList = []
        
        self.setBoard()
        self.shuffleButtons()
    
    def setPlayers(self):
        playerOne = Player()
        playerTwo = Player()
        playerList = [playerOne,]   
    
    def setBoard(self):
        for s in range(self.numberOfSounds):
            sound = Sound()
            sound.name = str(s)
            sound.audio = "chincol"
            self.soundList.append(sound)
    
        duplicateSoundList = self.soundList + self.soundList
        for b in range(self.numberOfButtons):
            button = Button()
            button.sound = duplicateSoundList[b]
            self.buttonList.append(button)
        return

    def shuffleButtons(self):        
        for b in range(self.numberOfButtons):
            r = random.randint(0, self.numberOfButtons-1)
            button0 = self.buttonList[b]
            button1 = self.buttonList[r]
            self.buttonList[b] = button1
            self.buttonList[r] = button0
        return
    
class Sound:
    def __init__(self):
        self.name = ""
        self.info = ""
        self.audio = ""
    def playSound():
        return
    def stopSound():
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

ecosystemBoard = Board()
