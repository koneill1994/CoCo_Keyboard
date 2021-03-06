# CoCo_Keyboard

Code and diagrams for wiring up a [TRS-80 Color Computer ("CoCo")](https://en.wikipedia.org/wiki/TRS-80_Color_Computer) keyboard to work as a modern USB input keyboard.  

![20210306_161344](https://user-images.githubusercontent.com/11077953/110221143-7d76d280-7e98-11eb-87b1-83520280bdfe.jpg)

## Background

The TRS-80 Color Computer was a line of home computers produced throughout the 80s and early 90s.  The keyboard I have seems to be produced for the CoCo model 1, which used calculator-style chiclet keys instead of more mechanically robust mechanical switches.  As a result, it was apparently common to replace the stock keyboard with a third-party model, which probably explains why this keyboard was orphaned from its parent system.  

The keyboard itself is connected to the rest of the computer via a 15-line ribbon cable.  The keys can be indexed via multiplexing; there are 7 common anode and 8 common cathode connections (or vice-versa).  To determine what key is being pressed we can put a charge on each of the cathode wires in turn, and then check each anode connection to determine if the key that sits on their intersection has been pressed.  

The following table shows the keys indexed by their intersection of the anode/cathode grid.  The lettering is arbitrary, but note that letter n is blank, as it represents the missing line separating the two lines on the left from the 13 on the right.  

<table class="table table-bordered table-hover table-condensed">
<thead><tr><th title="Field #1"></th>
<th title="Field #2">a</th>
<th title="Field #3">b</th>
<th title="Field #4">c</th>
<th title="Field #5">d</th>
<th title="Field #6">e</th>
<th title="Field #7">f</th>
<th title="Field #8">g</th>
<th title="Field #9">h</th>
<th title="Field #10">i</th>
<th title="Field #11">j</th>
<th title="Field #12">k</th>
<th title="Field #13">l</th>
<th title="Field #14">m</th>
<th title="Field #15">n</th>
<th title="Field #16">o</th>
<th title="Field #17">p</th>
</tr></thead>
<tbody><tr>
<td>a</td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
</tr>
<tr>
<td>b</td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
</tr>
<tr>
<td>c</td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
</tr>
<tr>
<td>d</td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
</tr>
<tr>
<td>e</td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
</tr>
<tr>
<td>f</td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
</tr>
<tr>
<td>g</td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
</tr>
<tr>
<td>h</td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
</tr>
<tr>
<td>i</td>
<td>SHIFT</td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
<td>BREAK</td>
<td>CLEAR</td>
<td>ENTER</td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
</tr>
<tr>
<td>j</td>
<td>/?</td>
<td>.&gt;</td>
<td>-=</td>
<td>,&lt;</td>
<td>;+</td>
<td>:*</td>
<td>9</td>
<td>8</td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
</tr>
<tr>
<td>k</td>
<td>7</td>
<td>6</td>
<td>5</td>
<td>4</td>
<td>3</td>
<td>2</td>
<td>1</td>
<td>0</td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
</tr>
<tr>
<td>l</td>
<td>SPACE</td>
<td>RIGHT ARROW</td>
<td>LEFT ARROW</td>
<td>DOWN ARROW</td>
<td>UP ARROW</td>
<td>Z</td>
<td>Y</td>
<td>X</td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
</tr>
<tr>
<td>m</td>
<td>W</td>
<td>V</td>
<td>U</td>
<td>T</td>
<td>S</td>
<td>R</td>
<td>Q</td>
<td>P</td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
</tr>
<tr>
<td>n</td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
</tr>
<tr>
<td>o</td>
<td>O</td>
<td>N</td>
<td>M</td>
<td>L</td>
<td>K</td>
<td>J</td>
<td>I</td>
<td>H</td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
</tr>
<tr>
<td>p</td>
<td>G</td>
<td>F</td>
<td>E</td>
<td>D</td>
<td>C</td>
<td>B</td>
<td>A</td>
<td>@</td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
<td> </td>
</tr>
</tbody></table>

I found this table by connecting a multimeter in continuity mode to each anode/cathode pair in turn, and then pressing each key until I determined how they were wired up.  

## Hardware

The keyboard is driven by an arduino pro micro ("Leonardo"), since it offers out-of-the-box usb functionality through its existing usb port.  

Any 16 pin 2.54mm pitch edge connector should be able to hold the ribbon cable securely, but since these are not as trivial to find now as they once might have been i opted to make my own using pogo pins and protoboard.  

![image](https://user-images.githubusercontent.com/11077953/110221557-dcd5e200-7e9a-11eb-8dac-e39db7e83497.png)

Its ugly but it gets the job done.  

Here's the wiring diagram, not too complicated: 

![image](https://user-images.githubusercontent.com/11077953/110221744-15c28680-7e9c-11eb-875d-d9554b5f81b5.png)

For ease of design I built it as though there were 16 data lines instead of 15, connecting up the missing line to digital 4 anyway.  The software doesn't make use of this connection, but it keeps the design elegant.  

After this, all that's left is to upload the software.  

![20210306_094607](https://user-images.githubusercontent.com/11077953/110221875-a8fbbc00-7e9c-11eb-939d-6ad47c0a4f88.jpg)

## Software

The code which runs the arduino can be found in "coco_keyboard_driver.ino".  It uses the Keyboard library to provide the core functionality, with the rest of the code either figuring out which key has been pressed, or whether the shift key has been held down so that it can send capitol letters instead of lowercase ones.  


