# Ensure the script exits on any error
set -e

PROJECT_FOLDER="microkernel-app"

printf "Starting the build process...\n"

# Build plugins (renamed from extensions to plugins)
printf "Building plugins...\n"
cd ./${PROJECT_FOLDER}/plugins
make -f Makefile
printf "Plugins Ready\n\n"

# Go back to the root directory
cd ..

# Build core
printf "Building core...\n"
cd ./core
make -f Makefile
printf "Core Ready\n\n"


# Run the core application
printf "Running the core application...\n"
echo "------------------------------------------------"
./core_obj
