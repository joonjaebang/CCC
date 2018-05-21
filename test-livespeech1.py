import os
import sys
import time
from pocketsphinx import LiveSpeech, get_model_path

model_path = get_model_path()

speech = LiveSpeech(
	verbose=False,
	sampling_rate=16000,
	buffer_size=2048,
	no_search=False,
	full_utt=False,
	hmm=os.path.join(model_path, 'en-us'),
	lm=os.path.join(model_path, 'en-us.lm.bin'),
	dic=os.path.join(os.path.dirname(os.path.realpath(__file__)), 'custom.dict')
)

for phrase in speech:
	print(phrase)
	sys.stdout.flush()
	
def wordToText( str ):
	if str==one:
		return 1
	elif str==two:
		return 2
	elif str==three:
		return 3
	elif str==four:
		return 4
	elif str==five:
		return 5
	elif str==six:
		return 6
	elif str==seven:
		return 7
	elif str==eight:
		return 8
	elif str==nine:
		return 9
