# Ensure the script exits on any error
set -e

PROJECT_FOLDER="dynamic_loading_lib_example"

printf "Starting the build process...\n"

# Build plugins
printf "Building plugins...\n"
cd ${PROJECT_FOLDER}/plugins
make
printf "Plugins Ready\n\n"

# Go back to the root directory
cd ..

# Build core
printf "Building core...\n"
cd ..
cd ${PROJECT_FOLDER}/core
make
printf "Core Ready\n\n"

# Go back to the root directory
cd ..

# Run the core application
printf "Running the core application...\n"
echo "------------------------------------------------"
printf "\n\n"
./core/core_obj
