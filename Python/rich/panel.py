from rich.panel import Panel
from rich.align import Align
from rich import print 

print(Align.center(Panel.fit("[bold yellow]Hi, I'm a Panel", border_style="cyan")))
