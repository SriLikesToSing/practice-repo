from pytube import YouTube 
from pytube import Playlist
import sys
import os
from os import path
import re

exit = False
songLinksList = []
destination = ""

print("Welcome to playlist downloader.")

print("input song youtube link.")
print("If you want to exit, type 'exit'")

songLink = input()

if songLink == "exit":
    sys.exit()

playlist = list(Playlist(''))

for x in playlist:

    yt = YouTube(x, use_oauth=True, allow_oauth_cache=True)
    stream = yt.streams.filter(only_audio=True)
    outFile = stream[0].download("playlist")

    base, ext = os.path.splitext(outFile)
    newFile = base + '.mp3'
    os.rename(outFile, newFile)

    print("song downloaded successfully.")



    




