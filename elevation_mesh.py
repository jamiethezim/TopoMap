import random


## Non Usable Function - intended only for testing purposes in generating random datasets
def populate_random():
	with open('elevation_data_points.txt', 'w') as filename:
		for i in range(40):
			val = random.randint(0, 100)
			filename.write("{}\n".format(val))

def read_data(filename):
	''' 
	input -> txt file of one integer per line
	output-> list of integers
	'''
	with open(filename, 'r') as filename:
		elevations = [int(x.strip('\n')) for x in filename.readlines()]
	return elevations	

## ---- MAYA AREA -------
import maya.cmds as cmds

def create_plane(self):
	if self._plane != None:
		self.delete_plane()
		self._plane = cmds.polyPlane(n='myPlane', sx=10, sy=10, w=100, h=100)

def transform(self, degree):
        i = 0
	points = read_data('elevation_data_points.txt')
	number_of_vertices = 121
        for i in range(number_of_vertices):
        	vertex = 'myPlane.vtx[{}]'.format(i)
        	delta = points[i]
		cmds.select(vertex)
		cmds.move(delta, moveY=True)
## ---- END MAYA AREA ----------


### Sandbox Area -- intended only for running via command line
if __name__ == '__main__':
	#populate_random()
	read_data('elevation_data_points.txt')
