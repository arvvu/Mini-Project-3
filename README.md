## Usage & Running Tests

To run from the terminal, navigate to the folder and run:

>./Denoiser

Then type the name of an input file in the 'tests' folder and an output file to be created in the same folder:

>noisy.txt output.txt

This is how it will look:

<img width="397" height="60" alt="Screenshot 2026-02-19 at 11 24 07 PM" src="https://github.com/user-attachments/assets/3db4a1c3-cb34-40f9-99f4-3ca089f258d6" />

## Copilot Integration

I tried to limit my usage of Copilot as much as possible. I googled most of the new topics necessary for this project (such as reading files), and wrote my own code.
When some of it inevitably didn't work, I used Copilot to explain what went wrong. I never had Copilot write entire lines of code for me. I also tested the code myself.

One thing Copilot did immensely help with was to figure out why my code wasn't reading the input file properly. It turns out the stringstream 'ss' that I originally had initialized
at the start of the code needed to be re-initialized every time the code moved to a new line in the input file. Without Copilot, it would have taken me much, much longer to realize that
this was the problem.
