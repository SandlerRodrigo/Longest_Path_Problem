<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <style>
        body {
            background-color: #1e1e1e;
            color: #fafafa;
            font-family: Arial, sans-serif;
        }
        .container {
            background-color: #2a3b4c;
            padding: 20px;
            border-radius: 10px;
            margin: 20px;
        }
        h1, h2 {
            color: #fafafa;
        }
        p {
            font-size: 20px;
        }
        .keyboard-shortcut {
            color: #999;
            background-color: #333;
            padding: 5px;
            border-radius: 5px;
        }
        .command {
            color: #ffcc00;
            font-style: italic;
        }
        .section {
            margin-bottom: 20px;
            padding-bottom: 10px;
            border-bottom: 1px solid #444;
        }
        .toc {
            margin-bottom: 20px;
        }
        .toc a {
            color: #ffcc00;
            text-decoration: none;
        }
        .toc a:hover {
            text-decoration: underline;
        }
    </style>
    <title>Instructions to Run the Code</title>
</head>
<body>
    <div class="container">
        <h1>Instructions to Run the Code</h1>
        <div class="toc">
            <h2>Table of Contents</h2>
            <ul>
                <li><a href="#intro">Introduction</a></li>
                <li><a href="#opening-terminal">Opening the Terminal</a></li>
                <li><a href="#compiling">Compiling the Code</a></li>
                <li><a href="#running-tests">Running Test Cases</a></li>
                <li><a href="#cleaning-up">Cleaning Up</a></li>
                <li><a href="#visualizing">Visualizing the Assignments</a></li>
                <li><a href="#output-image">Output Image</a></li>
                <li><a href="#conclusion">Conclusion</a></li>
            </ul>
        </div>
        <div id="intro" class="section">
            <h2>Introduction</h2>
            <p>You are not required to modify anything in the program files. <br> These instructions do NOT apply for Windows. They are intended for Unix-based systems like macOS and Linux.</p>
        </div>
        <div id="opening-terminal" class="section">
            <h2>Opening the Terminal</h2>
            <p>
                Open your terminal of preference, preferably the VSCode integrated terminal with:
                <br><br>
                <span class="keyboard-shortcut"><kbd>Ctrl</kbd> + <kbd>J</kbd></span>
            </p>
        </div>
        <div id="compiling" class="section">
            <h2>Compiling the Code</h2>
            <p>
                Type <span class="command">make</span> to compile the library and gain access to the fully compiled executable called <span class="command">main</span>.
            </p>
        </div>
        <div id="running-tests" class="section">
            <h2>Running Test Cases</h2>
            <p>
                We have a directory called <span class="command">catalogues</span>, containing different sizes of test cases. You can run them by typing <span class="command">./main &lt;desired test case's relative path&gt;</span>.
            </p>
        </div>
        <div id="cleaning-up" class="section">
            <h2>Cleaning Up</h2>
            <p>
                Don't forget to run <span class="command">make clean</span> after you are done using the code. Feel free to alter the <span class="command">main</span> file and make use of our different available methods as you wish.
            </p>
        </div>
        <div id="visualizing" class="section">
            <h2>Visualizing the Assignments</h2>
            <p>
                The <span class="command">make vis</span> command is set to execute the assignment description graph. You can change it to any other test case in the Makefile (note that large test cases might not work well with graph visualization).
            </p>
        </div>
        <div id="output-image" class="section">
            <h2>Output Image</h2>
            <p>The default <span class="command">make vis</span> command should output this image:</p>
            <img src="./assets/assets.png" alt="Visualization Output" style="max-width: 100%; height: auto; border: 1px solid #fafafa; border-radius: 10px;">
        </div>
        <div id="conclusion" class="section">
            <h2>Conclusion</h2>
            <p>If you have any questions or need further assistance, please contact [alex.gabriel@edu.pucrs.br] or [r.sandler@edu.pucrs.br].</p>
        </div>
    </div>
</body>
</html>
