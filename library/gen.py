import os


def generate_snippet_for_files(directory):
    snippets = []

    # Walk through the directory and get all .hpp files
    for filename in os.listdir(directory):
        if filename.endswith(".hpp"):
            # Get the file name without extension (use as trigger)
            trigger = os.path.splitext(filename)[0]

            # Read the content of the .hpp file
            with open(os.path.join(directory, filename), "r") as f:
                content = f.read()

            # Indent the content by 1 level for proper Snipmate formatting
            indented_content = "\n".join(
                ["    " + line for line in content.splitlines()]
            )

            # Generate the snippet
            snippet = f"""snippet {trigger}
{indented_content}
"""
            snippets.append(snippet)

    # Write the snippets to cpp.snippets file
    with open(os.path.join(directory, "cpp.snippets"), "w") as snipfile:
        snipfile.writelines(snippets)

    print("cpp.snippets file generated successfully!")


# Specify the directory containing the .hpp files
directory = "."
generate_snippet_for_files(directory)

os.system("mv cpp.snippets /Users/eric/.config/nvim/snippets/cp/cpp.snippets")
